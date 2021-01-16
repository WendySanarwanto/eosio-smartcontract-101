#include <toyhaus.hpp>

ACTION toyhaus::welcome(name arrival) {
  // require_auth(name("toyboss"));
  check( has_auth(arrival), "You are not our owner !" );
  check( arrival == name("toyboss"), "Please don't lie about your name!" );
  print ("Welcome to the toyhaus !");
};
