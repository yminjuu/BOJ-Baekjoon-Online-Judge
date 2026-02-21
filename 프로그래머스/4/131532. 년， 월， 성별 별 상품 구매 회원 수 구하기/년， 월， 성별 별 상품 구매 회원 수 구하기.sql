-- 코드를 입력하세요
with no_null as (
    select user_id, gender
    from user_info
    where gender is not null
)
select year(sales_date), month(sales_date), gender, count(distinct(user_id))
from no_null natural join online_sale
group by year(sales_date), month(sales_date), gender;