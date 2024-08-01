# Write your MySQL query statement below
-- select d1.customer_id,d1.order_date
-- from Delivery d1
-- JOIN Delivery d2
-- ON d1.customer_id = d2.customer_id
-- AND d1.order_date <= d2.order_date
-- GROUP BY d1.customer_id

select 
-- COUNT(customer_id) as one,
-- (SUM(if(min_order_date = min_customer_pref_delivery_date,1,0)* 100) ) as two,
ROUND((SUM(if(min_order_date = min_customer_pref_delivery_date,1,0)* 100) )/COUNT(customer_id),2) as immediate_percentage 
from
(
    select 
    min(order_date) as min_order_date,min(customer_pref_delivery_date) as min_customer_pref_delivery_date,customer_id
    from Delivery
    group by customer_id
    ) as new_table



