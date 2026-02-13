select REST_ID,	REST_NAME,	FOOD_TYPE,	FAVORITES, ADDRESS, ROUND(AVG(REVIEW_SCORE
), 2) as SCORE
from REST_INFO join REST_REVIEW using (REST_ID)
where ADDRESS like ('서울%')
group by REST_ID
order by 6 desc, 4 desc;