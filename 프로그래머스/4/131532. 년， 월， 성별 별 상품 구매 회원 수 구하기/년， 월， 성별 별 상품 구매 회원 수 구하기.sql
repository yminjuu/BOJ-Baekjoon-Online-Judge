-- 코드를 입력하세요
select year(sales_date), month(sales_date), gender, count(distinct(user_id))
from user_info natural join online_sale
where gender is not null
group by year(sales_date), month(sales_date), gender;