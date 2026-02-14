# 특정 연도의 최대 대장균 정보를 담은 테이블을 따로 관리
with MAX_COLONY as (
    select YEAR(DIFFERENTIATION_DATE) as YEAR, MAX(SIZE_OF_COLONY) as MAX_SIZE
    from ECOLI_DATA
    group by YEAR(DIFFERENTIATION_DATE)
) 
select m.year as YEAR, (m.MAX_SIZE-e.SIZE_OF_COLONY) as YEAR_DEV, e.ID as ID
from ECOLI_DATA e join MAX_COLONY m on (YEAR(e.DIFFERENTIATION_DATE)=m.YEAR)
order by 1, 2;