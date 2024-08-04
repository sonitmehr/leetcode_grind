# Write your MySQL query statement below
select Department,Employee,Salary from
(
select d.name as Department ,e.name as Employee , e.salary as Salary ,
dense_rank() over (partition by d.name order by e.salary desc) as ranks
from Employee e
JOIN Department d
ON e.departmentId = d.id ) as temp
WHERE ranks <= 3
