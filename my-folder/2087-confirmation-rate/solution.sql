# Write your MySQL query statement below
Select s.user_id
, ROUND(avg(if(c.action = 'timeout' or c.action is NULL,0,1)),2) as confirmation_rate

from Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id

