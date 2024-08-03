# Write your MySQL query statement below
select e1.name
from Employee e1
Join Employee e2
ON e1.id = e2.managerId
GROUP BY e1.id
HAVING COUNT(e2.managerId) >= 5
-- WHERE COUNT(e2.managerId) > 5
