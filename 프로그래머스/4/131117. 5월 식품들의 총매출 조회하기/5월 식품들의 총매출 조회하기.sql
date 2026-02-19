-- 코드를 입력하세요
SELECT f.product_id, f.product_name, f.price*o.amount as total_sales
from food_product f join (
    select product_id, sum(amount) as amount
    from food_order
    where produce_date like ('2022-05%')
    group by product_id
) o on (f.product_id=o.product_id)
order by 3 desc, 1;