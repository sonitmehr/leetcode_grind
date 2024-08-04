# Write your MySQL query statement below
select id,COUNT(id) as num from 
((
    select requester_id as id
    from RequestAccepted 

)
UNION ALL
(
    select accepter_id as id
    from RequestAccepted 

)) as new_table
group by id
order by num desc
LIMIT 1
