with recursive g as (
    select id, parent_id, 1 as generation
    from ecoli_data
    where parent_id is null
    
    union all
    
    select a.id, a.parent_id, generation+1 as generation
    from ecoli_data a, g b
    where b.id=a.parent_id
),

parents as (
    select distinct(parent_id) as parents_ids
    from ecoli_data
    where parent_id is not null
)

select sum(
    case when id not in (select parents_ids from parents) then 1
    else 0
    end
) as count, generation
from g
group by generation
order by generation;