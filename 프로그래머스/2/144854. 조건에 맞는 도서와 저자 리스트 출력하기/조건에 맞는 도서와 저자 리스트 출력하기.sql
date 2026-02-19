select book_id, author_name, date_format(published_date, '%Y-%m-%d')
from book natural join author
where category ='경제'
order by 3;