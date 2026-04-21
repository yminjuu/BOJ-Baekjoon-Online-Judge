select a.id, a.genotype, b.genotype as parent_genotype
from ecoli_data a join ecoli_data b on (a.parent_id = b.id)
where a.genotype & b.genotype = b.genotype # 부모가 가진 형질 다 가짐 => 비트연산
order by a.id;