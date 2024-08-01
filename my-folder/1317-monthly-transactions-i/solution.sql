# Write your MySQL query statement below
select DATE_FORMAT(trans_date,"%Y-%m") as month 
,country
, COUNT(IFNULL(country,1)) as trans_count
, SUM(if(state = 'approved',1,0)) as approved_count
, SUM(amount) as trans_total_amount 
, SUM(if(state = 'approved',amount,0)) as approved_total_amount 
from Transactions
GROUP BY country,MONTH(trans_date),YEAR(trans_date)
