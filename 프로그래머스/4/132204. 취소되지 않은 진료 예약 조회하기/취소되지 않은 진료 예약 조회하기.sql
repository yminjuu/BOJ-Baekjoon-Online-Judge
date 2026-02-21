with apt as (
    select apnt_no, pt_no, apnt_ymd, mddr_id, mcdp_cd
    from appointment
    where apnt_ymd like ('2022-04-13%') and apnt_cncl_yn='N' and mcdp_cd='cs'
)
-- 코드를 입력하세요
SELECT a.apnt_no, b.pt_name, b.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
from apt a join patient b on (a.pt_no=b.pt_no) join doctor d on (a.mddr_id=d.dr_id)
order by 6;