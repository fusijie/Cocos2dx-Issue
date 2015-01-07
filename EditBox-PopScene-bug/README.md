###EditBox-PopScene-Bug

---

`version:` v3.3

`Issue:` the editbox is invalid to key anything once you pushScene and popScene on the Mac platform.

the error log is 

>NSSecureTextFieldCell detected a field editor ((null)) that is not a NSTextView subclass designed to work with the cell. Ignoring...

`platform:` Mac

`reproduce:`

download the 2 classes(HelloWorldScene & HelloWorldScene2) to v3.3 HelloWorld Project.

