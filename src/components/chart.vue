<template>
  <div id="chart" class="rounded">
    <apexchart type="line" height="450"  :options="chartOptions" :series="series"></apexchart>
  </div>
</template>

<script>
import json from './data.json'

export default {


  data() {
    return {

      series: [{
        name: "Heapfiy",
        data: json.heapfiy,

      },
        {
          name: "Heapsort",
          data: json.heapsort,

        },
        {
          name: "Insert",
          data: json.insert,

        }],
      chartOptions: {
        chart: {
          height: 350,
          type: 'line',
          zoom: {
            enabled: false
          }
        },
        dataLabels: {
          enabled: false
        },
        stroke: {
          curve: 'straight'
        },
        title: {
          text: 'Compare Sorts',
          align: 'center'
        },
        grid: {
          row: {
            colors: ['#f3f3f3', 'transparent'], // takes an array which will be repeated on columns
            opacity: 0.5
          },
        },
        xaxis: {
          categories: json.n,
        }
      },

    };
  }
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;

}
a {
  color: #42b983;
}
</style>
