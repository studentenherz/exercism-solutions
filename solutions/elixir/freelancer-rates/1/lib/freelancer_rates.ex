defmodule FreelancerRates do
  def daily_rate(hourly_rate) do
    8.0 * hourly_rate
  end

  def apply_discount(before_discount, discount) do
    before_discount * (1 - discount / 100)
  end

  def monthly_rate(hourly_rate, discount) do
    trunc(Float.ceil(22 * daily_rate(apply_discount(hourly_rate, discount))))
  end

  def days_in_budget(budget, hourly_rate, discount) do
    Float.floor(budget / daily_rate(apply_discount(hourly_rate, discount)), 1)
  end
end
