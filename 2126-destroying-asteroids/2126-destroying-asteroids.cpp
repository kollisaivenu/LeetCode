class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mass_ll = mass;
        for(int asteroid: asteroids) {
            if(mass_ll < asteroid) {
                return false;
            }

            mass_ll += asteroid;
        } 

        return true;
        
    }
};