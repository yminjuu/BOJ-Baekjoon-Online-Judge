select item_id, item_name
from item_info natural join item_tree
where parent_item_id is null
order by 1;