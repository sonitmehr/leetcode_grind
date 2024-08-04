# Write your MySQL query statement below

select employee_id from Employees
Where  salary < 30000 AND manager_id 
not in 
(
    select e1.employee_id as employee_id_test
from Employees e1
JOIN Employees e2
ON e1.employee_id = e2.manager_id
) order by employee_id
