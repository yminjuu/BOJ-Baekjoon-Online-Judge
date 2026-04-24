select id, fish_name, length
from fish_info join fish_name_info using (fish_type)
where (length, fish_type) in (
    select max(length), fish_type
    from fish_info
    group by fish_type
)
group by fish_type
order by 1;