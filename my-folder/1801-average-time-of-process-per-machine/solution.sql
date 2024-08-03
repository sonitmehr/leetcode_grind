# Write your MySQL query statement below
select a1.machine_id
, ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time
 from Activity a1
 JOIN Activity a2
 ON a1.activity_type = 'start' AND a2.activity_type = 'end' 
 AND a1.machine_id = a2.machine_id
 AND a1.process_id = a2.process_id
 GROUP BY a1.machine_id
