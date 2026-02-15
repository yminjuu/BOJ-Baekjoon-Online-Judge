select category, price as max_price, product_name
from food_product
where (price, category) in 
    (
    select max(price), category
    from food_product
    group by category
    having  category in ('과자', '국', '김치', '식용유'))
order by 2 desc;