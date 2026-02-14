with recursive generation_table as (
    # anchor
    select ID, PARENT_ID, 1 as generation
    from ECOLI_DATA
    where PARENT_ID is null
    
    union all
    
    # recursive
    select e.ID, e.PARENT_ID, g.generation+1 as generation
    from ECOLI_DATA e 
    join generation_table g 
    where g.ID=e.PARENT_ID
)
select COUNT(a.ID) as COUNT, a.generation as GENERATION
FROM generation_table a
where a.ID not in (
    select b.PARENT_ID
    from generation_table b
    where b.generation = a.generation+1
)
group by a.generation
order by a.generation;