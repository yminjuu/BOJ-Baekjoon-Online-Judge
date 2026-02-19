-- 코드를 입력하세요
with r as 
( select member_id, review_text, review_date
 from rest_review
 where member_id =
(SELECT member_id
from rest_review
group by member_id
order by count(*) desc
limit 1)) 
select m.member_name, review_text, date_format(review_date, '%Y-%m-%d')
from member_profile m join r on (m.member_id=r.member_id)
order by 3, 2;