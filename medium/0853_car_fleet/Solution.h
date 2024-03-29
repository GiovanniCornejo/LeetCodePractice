/**
 * There are n cars going to the same destination along a one-lane road.
 * The destination is target miles away.
 *
 * You are given two integer array position and speed, both of length n,
 * where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).
 *
 * A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed.
 * The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).
 *
 * A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
 * If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
 *
 * Return the number of car fleets that will arrive at the destination.
 *
 * Constraints:
 * n == position.length == speed.length
 * 1 <= n <= 10^5
 * 0 < target <= 10^6
 * 0 <= position[i] < target
 * All the values of position are unique.
 * 0 < speed[i] <= 10^6
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <algorithm>

class Solution
{
public:
    int carFleet(const int target, std::vector<int> &position, std::vector<int> &speed)
    {
        // Sort the cars by position
        std::vector<Car> cars(position.size());
        for (int i = 0; i < position.size(); ++i)
            cars[i] = Car{position[i], speed[i]};
        std::sort(cars.begin(), cars.end(), [](const Car &a, const Car &b)
                  { return a.position < b.position; });

        // Keep track of time to destinations (stack)
        std::vector<float> carTimes;

        // Iterate through cars in reverse order
        for (auto itr = cars.rbegin(); itr != cars.rend(); ++itr)
        {
            // Calculate current time to destination
            float time = (target - itr->position) / static_cast<float>(itr->speed);

            // Push time to stack
            carTimes.push_back(time);

            // Cars overlap if current car is slower than the previous cars
            if (carTimes.size() >= 2 && time <= carTimes[carTimes.size() - 2])
                carTimes.pop_back();
        }

        return carTimes.size();
    }

private:
    struct Car
    {
        int position;
        int speed;

        Car(int p = 0, int s = 0) : position{p}, speed{s} {}
    };
};
#endif