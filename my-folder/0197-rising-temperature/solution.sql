# Write your MySQL query statement below
select w2.id
from Weather w1
JOIN Weather w2
ON datediff(w2.recordDate,w1.recordDate) = 1
AND w1.temperature < w2.temperature 
