# Write your MySQL query statement below
Select 
DATE_FORMAT(trans_date,'%Y-%m') as month,
country,
COUNT(IFNULL(country,0)) as trans_count,
SUM(if(state = 'approved',1,0)) as approved_count,
SUM(amount) as trans_total_amount,
SUM(if(state = 'approved',amount,0)) as approved_total_amount
from Transactions
group by country,year(trans_date),month(trans_date)
