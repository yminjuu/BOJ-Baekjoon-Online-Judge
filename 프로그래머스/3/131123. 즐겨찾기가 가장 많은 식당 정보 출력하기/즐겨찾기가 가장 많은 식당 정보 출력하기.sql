-- 코드를 입력하세요

SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
from REST_INFO
where (FOOD_TYPE, favorites) in (
    select FOOD_TYPE, max(favorites)
    from REST_INFO
    group by FOOD_TYPE
)
order by food_type desc;
