-- 코드를 입력하세요
SELECT cart_id
from cart_products
where name = 'Yogurt' or name= 'Milk'
group by cart_id
having max(name)='Yogurt' and min(name)='Milk'
order by 1;