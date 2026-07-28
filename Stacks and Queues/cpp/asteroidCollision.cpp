// Problem Statement:Given an array of asteroids where each element represents an asteroid's size and direction (positive for right, negative for left), simulate the collisions of asteroids. 
// When two asteroids collide, the smaller one is destroyed, and the larger one continues moving. Return the state of the asteroids after all collisions.

// Problem Link: https://www.codingninjas.com/studio/problems/asteroid-collision_977232?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
using namespace std;

vector<int> collidingAsteroids(vector<int>& asteroids) {
    vector<int> st;
    for (int asteroid : asteroids) {
        if (asteroid > 0) {
            st.push_back(asteroid); // Push right-moving asteroids onto the stack
        } else {
            while (!st.empty() && st.back() > 0 && st.back() < -asteroid) {
                st.pop_back(); // Destroy smaller right-moving asteroids
            }
            if (!st.empty() && st.back() == -asteroid) {
                st.pop_back(); // Both asteroids are destroyed
            } else if (!st.empty() && st.back() > -asteroid) {
                // Left-moving asteroid survives
            } else {
                st.push_back(asteroid); // Left-moving asteroid is pushed onto the stack
            }
        }
    }
    return st;
}
