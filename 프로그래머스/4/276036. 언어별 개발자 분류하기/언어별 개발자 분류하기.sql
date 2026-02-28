

    select
    case
        when (skill_code & (select code from skillcodes where name='Python') > 0) and exists (select 1 from skillcodes where code & skill_code > 0 and category='Front end') then 'A'
        when (skill_code & (select code from skillcodes where name='C#')>0) then 'B'
        when exists (select 1 from skillcodes where code & skill_code > 0 and category='Front end') then 'C'
        else null
    end as grade, id, email
    from developers
    group by id, email, grade
    having grade is not null
    order by grade, id;
