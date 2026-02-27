with recursive g as (
    -- anchor
    select id, parent_id, 1 as generation
    from ecoli_data
    where parent_id is null
    
    union all
    
    -- recursive
    select e.id, e.parent_id, g.generation+1 as generation
    from ecoli_data e, g
    where g.id= e.parent_id
)

-- 만약 여기서 0인 그룹도 포함되게 하려면??
select count(id) as count, generation
from g
where id not in (
    select parent_id
    from ecoli_data
    where parent_id is not null
)
group by generation
order by generation;