require('dotenv').config({ path: 'atlas-credentials.env' }); // Load user's env file
const express = require('express');
const path = require('path');
const app = express();

app.use(express.json());

// API Routes (Simulating Vercel Serverless Functions)
app.post('/api/auth/register', async (req, res) => {
  const handler = require('./api/auth/register.js');
  await handler(req, res);
});

app.post('/api/auth/login', async (req, res) => {
  const handler = require('./api/auth/login.js');
  await handler(req, res);
});

app.all('/api/progress', async (req, res) => {
  const handler = require('./api/progress.js');
  await handler(req, res);
});

// Serve static files from root directory
app.use(express.static(__dirname));

// Fallback to index.html
app.use((req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

const PORT = process.env.PORT || 8000;
app.listen(PORT, () => {
  console.log(`=========================================`);
  console.log(`Local Dev Server running at: http://localhost:${PORT}`);
  console.log(`=========================================`);
});
