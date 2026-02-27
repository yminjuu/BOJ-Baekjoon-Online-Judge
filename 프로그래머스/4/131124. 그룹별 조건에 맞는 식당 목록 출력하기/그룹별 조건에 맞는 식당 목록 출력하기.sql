-- 코드를 입력하세요
-- 최대 리뷰 개수
with max as (
    select count(review_id) as cnt
    from member_profile natural join rest_review
    group by member_id
),

maxid as (select member_id
from member_profile natural join rest_review
group by member_id
having count(review_id) = (
    select max(cnt)
    from max
))

select MEMBER_NAME,	REVIEW_TEXT,	date_format(REVIEW_DATE, '%Y-%m-%d')
from  member_profile natural join rest_review
where member_id in (
    select member_id
    from maxid
) order by 3, 2;