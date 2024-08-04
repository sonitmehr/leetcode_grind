# Write your MySQL query statement below

select ROUND(sum(tiv_2016),2) as tiv_2016 
from Insurance
where pid not in

(
    select i1.pid
from Insurance i1
JOIN Insurance i2
ON i1.pid != i2.pid
AND i1.lat = i2.lat 
AND i1.lon =i2.lon)

and tiv_2015 in (
    select tiv_2015
    from Insurance 
    group by tiv_2015
    having count(tiv_2015) >= 2
)
