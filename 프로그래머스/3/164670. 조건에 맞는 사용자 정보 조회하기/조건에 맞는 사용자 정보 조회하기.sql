-- 코드를 입력하세요
select user_id, nickname, concat(city, ' ', STREET_ADDRESS1,' ', STREET_ADDRESS2) as 전체주소, concat(left(tlno, 3),'-',substr(tlno, 4, 4),'-', substr(tlno, 8, 4)) as 전화번호
from used_goods_user
where user_id in
(SELECT writer_id
from used_goods_board
group by writer_id
having count(board_id)>=3)
order by 1 desc;