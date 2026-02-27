select year(DIFFERENTIATION_DATE) as year, (max(size_of_colony) over (partition by year(DIFFERENTIATION_DATE)) - size_of_colony) as year_dev, id
from ecoli_data
order by 1, 2;