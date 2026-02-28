# 1. ntile 사용하는 풀이
# select length, ntile(4) over (order by length)
# from fish_info
# order by length;


# 2. group by, having 사용하는 

# avg만 구하는 테이블
select count(*) as fish_count, max(length) as max_length, fish_type
from fish_info
group by fish_type
having avg (
    case
        when length<=10 then 10
        else length
    end
) >= 33
order by 3;