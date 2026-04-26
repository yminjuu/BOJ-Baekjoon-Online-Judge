with users_joined_2021 as (
    select user_id
    from user_info
    where joined like '2021%'
)

select year(SALES_DATE) as year, month(SALES_DATE) as month
, count(distinct(user_id)) as purchased_users, round(count(distinct(user_id)) / (
    select count(user_id)
    from users_joined_2021
), 1) as purchased_ratio
from online_sale
where user_id in (
    select user_id
    from users_joined_2021
)
group by year(SALES_DATE), month(SALES_DATE)
order by 1,2;