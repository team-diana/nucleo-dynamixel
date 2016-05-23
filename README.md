# nucleo-dynamixel
Library for working with dynamixel servomotors, designed for stm32  nucleo boards

## Document the code

See existing documentation, use the same format. Use the \brief, \param, \return keywords

## Update doxygen

```bash
# in the project directory
# update doxygen html files
doxygen
# commit changes
git push origin master
# push update on gh-pages
git subtree push --prefix docs/html origin gh-page
```
