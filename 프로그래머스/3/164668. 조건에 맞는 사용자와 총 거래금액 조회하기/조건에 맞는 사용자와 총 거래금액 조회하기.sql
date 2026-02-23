-- 코드를 입력하세요
with writer as (SELECT writer_id, sum(price) as total_sales
from used_goods_board
where status='done'
group by writer_id
having sum(price)>=700000)

select u.user_id, u.nickname, w.total_sales as total_sales
from used_goods_user u join writer w on (w.writer_id=u.user_id)
order by 3;