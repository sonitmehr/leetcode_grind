# Write your MySQL query statement below

(
    select u.name as results
from MovieRating m
CROSS JOIN Users u
ON m.user_id = u.user_id
group by m.user_id
order by COUNT(m.movie_id) DESC,u.name ASC
LIMIT 1
) 
UNION all

(
  select mov.title as results
  from MovieRating m
  JOIN Movies mov
  ON m.movie_id = mov.movie_id
  WHERE MONTH(m.created_at) = 2 AND YEAR(m.created_at) = 2020 
  group by m.movie_id
  order by AVG(m.rating) DESC, mov.title ASC
  LIMIT 1

) 
