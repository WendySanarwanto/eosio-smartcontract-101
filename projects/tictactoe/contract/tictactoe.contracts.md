<h1 class="contract">welcome</h1>
--
spec-version: 0.0.1  
title: welcome  
summary: This action will print welcome message to specified `host`'s & `opponent`'s names on console. No changes will be made against __games__ table.  

<h1 class="contract">create</h1>
--
spec-version: 0.0.1  
title: create  
summary: This action will insert a new entry into the __games__ table. If an entry exists by the specified either `host` or `opponent` parameters, this action will raise `There is a game played by specified host/chalelnger.` errors. If both `host` & `opponent` parameters have same name, this action will raise `Both challenger and host cannot be same player.` error. Otherwise, a new record is created on __games__ table. The __games__ table is a the multi index table. The ram costs are paid by the smart contract.

<h1 class="contract">close</h1>
--
spec-version: 0.0.1  
title: close  
summary: This action will remove a matched entry by specified `host` & `opponent` parameters, from __games__ table. The __games__ table is a the multi index table. The ram costs are paid by the smart contract.  
