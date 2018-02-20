.PHONY: clean All

All:
	@echo "----------Building project:[ radiation - Debug ]----------"
	@cd "radiation" && "$(MAKE)" -f  "radiation.mk"
clean:
	@echo "----------Cleaning project:[ radiation - Debug ]----------"
	@cd "radiation" && "$(MAKE)" -f  "radiation.mk" clean
