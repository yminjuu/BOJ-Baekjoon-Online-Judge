with recursive g as (
    select id, parent_id, 1 as generation
    from ecoli_data
    where parent_id is null
    
    union all
    
    select a.id, a.parent_id, generation+1 as generation
    from ecoli_data a join g
    where a.parent_id = g.id
)

select count(id) as count, generation
from g
where id not in (
    select parent_id
    from g
    where parent_id is not null
)
group by generation
order by generation;