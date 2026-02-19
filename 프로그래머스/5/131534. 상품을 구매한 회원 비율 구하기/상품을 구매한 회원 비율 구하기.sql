-- 코드를 입력하세요
with tot as (
    select count(user_id) as t
    from user_info
    where joined like '2021%'
)
 -- 21년에 가입한 회원들의 월별 주문 횟수
select year(o.sales_date), month(o.sales_Date), count(distinct(u.user_id)), round(count(distinct(u.user_id)) / tot.t, 1)
from user_info u join online_sale o on (u.user_id=o.user_id) join tot
where u.joined like '2021%'
group by year(o.sales_date), month(o.sales_Date)
order by 1,2;