# Write your MySQL query statement below
SELECT w1.id from Weather w1, Weather w2 where TO_DAYS(w1.recordDate) - TO_DAYS( w2.recordDate) = 1 AND w1.temperature > w2.temperature;