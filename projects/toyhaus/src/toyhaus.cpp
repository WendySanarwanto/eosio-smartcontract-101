#include <toyhaus.hpp>

ACTION toyhaus::addtoy(uint64_t id, string toyname, string toydescrip, uint64_t quantity) {
  // require_auth(name("toyboss"));
  check( has_auth(name( "toyboss" )), "You are not our owner !" );
  toyshelf_table _toyshelf(get_self(), get_self().value);

  // Find toy by specified id
  auto itr = _toyshelf.find(id); 
  if (itr == _toyshelf.end()) {
    print ("Item does not exist. Creating a new item with id:", id);
    // Item does not exist. Create a new item.
    _toyshelf.emplace( get_self(), [&](toy& new_toy_row){
      new_toy_row.id = _toyshelf.available_primary_key();
      new_toy_row.toyname = toyname;
      new_toy_row.toydescrip = toydescrip;
      new_toy_row.quantity = quantity;      
    }); 
  } else {
    print ("Modifying an item with id:", id);
    _toyshelf.modify(itr, get_self(), [&](toy& row_to_modify){
      row_to_modify.toyname = toyname;
      row_to_modify.toydescrip = toydescrip;    
      row_to_modify.quantity = quantity;
    });
  }
};

ACTION toyhaus::removetoy(uint64_t id) {
  check( has_auth(name( "toyboss" )), "You are not our owner !" );
  toyshelf_table _toyshelf(get_self(), get_self().value);

  auto itr = _toyshelf.find(id); 
  check( itr != _toyshelf.end(), "Toy with given id does not exist. Nothing to delete.");

  print ("Item with specified id does exist. Deleting the item.");
  _toyshelf.erase(itr);
}
