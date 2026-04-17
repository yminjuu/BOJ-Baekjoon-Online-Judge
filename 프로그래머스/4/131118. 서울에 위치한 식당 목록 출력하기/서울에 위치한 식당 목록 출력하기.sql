select a.rest_id, a.rest_name, a.food_type, favorites, address, round(avg(review_score), 2) as score
from (
    select rest_id, rest_name, food_type, favorites, address
    from rest_info
    where address like '서울%'
) a join rest_review b on (a.rest_id = b.rest_id)
group by rest_id, rest_name, food_type
order by score desc, favorites desc;