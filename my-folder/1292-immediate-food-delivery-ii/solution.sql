# Write your MySQL query statement below


select 
ROUND(
    (SUM(
        if(datediff(min_customer_pref_delivery_date,min_order_date) = 0,1,0)
        ) * 100)
        / 
        (select count(distinct customer_id) from Delivery)
,2)
 as immediate_percentage 
from

(
    select customer_id,
min(order_date) as min_order_date,
min(customer_pref_delivery_date) as min_customer_pref_delivery_date
from Delivery
group by customer_id
) as new_table
