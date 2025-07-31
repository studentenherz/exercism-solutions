space_age("Earth", AgeSec, Years) :- Years is AgeSec / 31557600.
space_age("Mercury", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 0.2408467.
space_age("Venus", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 0.61519726.
space_age("Mars", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 1.8808158.
space_age("Jupiter", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 11.862615.
space_age("Saturn", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 29.447498.
space_age("Uranus", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 84.016846.
space_age("Neptune", AgeSec, Years) :- 
	space_age("Earth", AgeSec, EarthYears),
	Years is EarthYears / 164.79132.