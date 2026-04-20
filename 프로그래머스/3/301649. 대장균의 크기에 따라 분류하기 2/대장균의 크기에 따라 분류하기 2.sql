# NTILE(4) OVER (ORDER BY SIZE_OF_COLONY ASC) as COLONY_TILE

select a.id, case
    when a.colony_ntile = 1 then 'LOW'
    when a.colony_ntile = 2 then 'MEDIUM'
    when a.colony_ntile = 3 then 'HIGH'
    else 'CRITICAL'
end as colony_name
from (
    select id, ntile(4) over (order by size_of_colony) as colony_ntile
    from ecoli_data
) as a
order by id;