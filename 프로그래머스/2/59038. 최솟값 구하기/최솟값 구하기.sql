-- 코드를 입력하세요
SELECT DATETIME as 시간
from animal_ins
where DATETIME = (
    select min(DATETIME)
    from animal_ins
);