const connectToDatabase = require('./utils/db');
const User = require('./models/User');
const jwt = require('jsonwebtoken');

const JWT_SECRET = process.env.JWT_SECRET || 'fallback-secret-striver79';

const authenticate = (req) => {
  const authHeader = req.headers.authorization;
  if (!authHeader || !authHeader.startsWith('Bearer ')) {
    throw new Error('Unauthorized');
  }
  const token = authHeader.split(' ')[1];
  return jwt.verify(token, JWT_SECRET);
};

module.exports = async (req, res) => {
  try {
    await connectToDatabase();
    
    let decoded;
    try {
      decoded = authenticate(req);
    } catch (err) {
      return res.status(401).json({ message: 'Unauthorized' });
    }

    if (req.method === 'GET') {
      const user = await User.findById(decoded.userId);
      if (!user) return res.status(404).json({ message: 'User not found' });
      return res.status(200).json({ solvedProblems: user.solvedProblems });
    } 
    
    if (req.method === 'POST') {
      const { solvedProblems } = req.body;
      if (!Array.isArray(solvedProblems)) {
        return res.status(400).json({ message: 'solvedProblems must be an array' });
      }
      
      const user = await User.findByIdAndUpdate(
        decoded.userId,
        { solvedProblems },
        { new: true }
      );
      if (!user) return res.status(404).json({ message: 'User not found' });
      
      return res.status(200).json({ solvedProblems: user.solvedProblems });
    }

    return res.status(405).json({ message: 'Method Not Allowed' });
  } catch (error) {
    console.error('Progress API error:', error);
    res.status(500).json({ message: 'Internal Server Error' });
  }
};
