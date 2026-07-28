# Problem Statement:Given an array of asteroids where each element represents an asteroid's size and direction (positive for right, negative for left), simulate the collisions of asteroids. 
# When two asteroids collide, the smaller one is destroyed, and the larger one continues moving. Return the state of the asteroids after all collisions.

# Problem Link: https://www.codingninjas.com/studio/problems/asteroid-collision_977232?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

def colliding_asteroids(asteroids):
    st = []
    for asteroid in asteroids:
        if asteroid > 0:
            st.append(asteroid) # Push right-moving asteroids onto the stack
        else:
            while st and st[-1] > 0 and st[-1] < -asteroid:
                st.pop() # Destroy smaller right-moving asteroids
            if st and st[-1] == -asteroid:
                st.pop() # Both asteroids are destroyed
            elif st and st[-1] > -asteroid:
                pass # Left-moving asteroid survives
            else:
                st.append(asteroid) # Left-moving asteroid is pushed onto the stack
                
    return st
